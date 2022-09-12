/*
 * print.c
 * code to print stuff out.
 *
 * Author: Saumya Debray
 */
#include <stdarg.h>
#include "global.h"
#include "protos.h"
#include "syntax-tree.h"

static void indent(int n);
static void printBinop(int op);
static void printUnop(int op);

 

extern int ErrorNum;
extern int IntconNum;
extern int CharconNum;
extern int StringconNum;
extern int VarNum;
extern int ArraySubscriptNum;
extern int PlusNum;
extern int UnaryMinusNum;
extern int BinaryMinusNum;
extern int MultNum;
extern int DivNum;
extern int EqualsNum;
extern int NeqNum;
extern int LeqNum;
extern int LtNum;
extern int GeqNum;
extern int GtNum;
extern int LogicalAndNum;
extern int LogicalOrNum;
extern int LogicalNotNum;
extern int FunCallNum;
extern int AssgNum;
extern int ReturnNum;
extern int ForNum;
extern int WhileNum;
extern int IfNum;
extern int STnodeListNum;


/*
 * printSyntaxTree(t,n) -- print out a syntax tree.  t is a pointer
 * to the syntax tree to be printed out, n gives the no. of spaces
 * of indentation to provide before printing t.
 * 
 */
void printSyntaxTree(tnode *t, int n, int depth)
{
  symtabnode *stptr;
  tnode *tntmp0;

  printf("%d:", depth);
  indent(n);

  if (t == NULL) {
    printf("-null-\n");
    return;
  }

  switch (t->ntype) {
  case Error:
    printf("-error-\n");
    break;

  case Intcon:
    printf("intcon(%d);\n", stIntcon(t));
    break;

  case Charcon:
    printf("charcon(%d);\n", stCharcon(t));
    break;

  case Stringcon:
    printf("str(%s);\n", stStringcon(t));
    break;

  case Var:
    stptr = stVar(t);
    printf("id(name=%s, scope=%s);\n", 
	   stptr->name,
	   (stptr->scope == Global ? "G" : "L"));
    break;

  case ArraySubscript:
    stptr = stArraySubscript_Array(t);
    printf("arrayRef(id(name=%s, scope=%s),\n",
	   stptr->name,
	   (stptr->scope == Global ? "G" : "L"));
    printSyntaxTree(stArraySubscript_Subscript(t), n+9, depth+1);
    printf("%d:", depth);
    indent(n+8);
    printf(")\n");
    break;

  case UnaryMinus:
  case LogicalNot:
    printUnop(t->ntype);
    printf("(\n");
    printSyntaxTree(stUnop_Op(t), n+2, depth+1);
    printf("%d:", depth);
    indent(n);
    printf(")\n");
    break;

  case Plus:
  case BinaryMinus:
  case Mult:
  case Div:
  case Equals:
  case Neq:
  case Leq:
  case Lt:
  case Geq:
  case Gt:
  case LogicalAnd:
  case LogicalOr:
    printBinop(t->ntype);
    printf("(\n");
    printSyntaxTree(stBinop_Op1(t), n+2, depth+1);
    printSyntaxTree(stBinop_Op2(t), n+2, depth+1);
    printf("%d:", depth);
    indent(n);
    printf(")\n");
    break;

  case FunCall:
    stptr = stFunCall_Fun(t);
    printf("CALL: callee=%s\n", stptr->name);
    printf("%d:", depth);
    indent(n);
    printf("  args:\n");
    printSyntaxTree(stFunCall_Args(t), n+4, depth+1);
    break;

  case Assg:
    printf("ASSG:\n");
    printf("%d:", depth);
    indent(n);
    printf("  Lhs:\n");
    printSyntaxTree(stAssg_Lhs(t), n+4, depth+1);
    printf("%d:", depth);
    indent(n);
    printf("  Rhs:\n");
    printSyntaxTree(stAssg_Rhs(t), n+4, depth+1);
    break;

  case Return:
    printf("RETURN:\n");
    printSyntaxTree(stReturn(t), n+2, depth+1);
    break;

  case For:
    printf("FOR\n");
    printf("%d:", depth);
    indent(n);
    printf("  init:\n");
    printSyntaxTree(stFor_Init(t), n+4, depth+1);
    printf("%d:", depth);
    indent(n);
    printf("  test:\n");
    printSyntaxTree(stFor_Test(t), n+4, depth+1);
    printf("%d:", depth);
    indent(n);
    printf("  update:\n");
    printSyntaxTree(stFor_Update(t), n+4, depth+1);
    printf("%d:", depth);
    indent(n);
    printf("  body:\n");
    printSyntaxTree(stFor_Body(t), n+4, depth+1);
    printf("%d:", depth);
    indent(n);
    printf("ENDFOR\n");
    break;

  case While:
    printf("WHILE\n");
    printSyntaxTree(stWhile_Test(t), n+4, depth+1);
    printf("%d:", depth);
    printf("  body:\n ");
    printSyntaxTree(stWhile_Body(t), n+4, depth+1);
    printf("%d:", depth);
    indent(n);
    printf("ENDWHILE\n");
    break;

  case If:
    printf("IF\n");
    printSyntaxTree(stIf_Test(t), n+4, depth+1);
    printf("%d:", depth);
    indent(n);
    printf("  then:\n");
    printSyntaxTree(stIf_Then(t), n+4, depth+1);
    printf("%d:", depth);
    indent(n);
    printf("  else:\n");
    printSyntaxTree(stIf_Else(t), n+4, depth+1);
    printf("%d:", depth);
    indent(n);
    printf("ENDIF\n");
    break;

  case STnodeList:  /* list of syntax tree nodes */
    printf("{\n");
    /* iterate down the list, printing out each tree in the list in turn */
    for (tntmp0 = t; tntmp0 != NULL; tntmp0 = stList_Rest(tntmp0)) {
      printSyntaxTree(stList_Head(tntmp0),n+2, depth+1);
    }
    printf("%d:", depth);
    indent(n);
    printf("}\n");
    break;

  default:
    fprintf(stderr, "Unknown syntax tree node type %d\n", t->ntype);
  }

  return;
}

/*
 * indent(n) -- insert n spaces.
 */
static void indent(int n)
{
  if (n < 0) return;

  while (n-- > 0) {
    putc(' ', stdout);
  }  
}

/*
 * printBinop(op) -- print out the syntax tree representation of a binary op
 */
static void printBinop(int op)
{
  switch (op) {
  case Plus:
    putc('+', stdout);
    break;
  case BinaryMinus:
    putc('-', stdout);
    break;
  case Mult:
    putc('*', stdout);
    break;
  case Div:
    putc('/', stdout);
    break;
  case Equals:
    printf("==");
    break;
  case Neq:
    printf("!=");
    break;
  case Leq:
    printf("<=");
    break;
  case Lt:
    putc('<', stdout);
    break;
  case Geq:
    printf(">=");
    break;
  case Gt:
    putc('>', stdout);
    break;
  case LogicalAnd:
    printf("&&");
    break;
  case LogicalOr:
    printf("||");
    break;
  }

  return;
}

/*
 * printUnop(op) -- print out the syntax tree representation of a unary op
 */
static void printUnop(int op)
{
  switch (op) {
  case UnaryMinus:
    putc('-', stdout);
    break;
    
  case LogicalNot:
    putc('!', stdout);
    break;
  }

  return;
}


/*
HW0, this function counts the variable and functioncall
*/
void printNode(tnode *t, int n, int depth)
{



  symtabnode *stptr;
  tnode *tntmp0;

  //printf("%d:", depth);
  //indent(n);

  if (t == NULL) {
    //printf("-null-\n");
    return;
  }

  switch (t->ntype) {
  case Error:
    ErrorNum++;
    // printf("Error:%d", EqualsNum);
    //printf("-error-\n%d",ErrorNum);
    break;

  case Intcon:
    IntconNum++;
    //printf("intcon(%d);\n", stIntcon(t));
    break;

  case Charcon:
    CharconNum++;
    //printf("charcon(%d);\n", stCharcon(t));
    break;

  case Stringcon:
    StringconNum++;
    //printf("str(%s);\n", stStringcon(t));
    break;

  case Var:
    VarNum++;
    stptr = stVar(t);
    //printf("id(name=%s, scope=%s);\n", stptr->name,(stptr->scope == Global ? "G" : "L"));
    break;

  case ArraySubscript:
    ArraySubscriptNum++;
    stptr = stArraySubscript_Array(t);
    //printf("arrayRef(id(name=%s, scope=%s),\n",stptr->name,(stptr->scope == Global ? "G" : "L"));
    printNode(stArraySubscript_Subscript(t), n+9, depth+1);
    //printf("%d:", depth);
    //indent(n+8);
    //printf(")\n");
    break;

  case UnaryMinus:
    UnaryMinusNum++;
    break;

  case LogicalNot:
    LogicalNotNum++;
    //printUnop(t->ntype);
    //printf("(\n");
    printNode(stUnop_Op(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case Plus:
    PlusNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case BinaryMinus:
    BinaryMinusNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case Mult:
    MultNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case Div:
    DivNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case Equals:
    EqualsNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case Neq:
    NeqNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case Leq:
    LeqNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case Lt:
    LtNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case Geq:
    GeqNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case Gt:
    GtNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case LogicalAnd:
    LogicalAndNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case LogicalOr:
    LogicalOrNum++;
    //printBinop(t->ntype);
    //printf("(\n");
    printNode(stBinop_Op1(t), n+2, depth+1);
    printNode(stBinop_Op2(t), n+2, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf(")\n");
    break;

  case FunCall:
    FunCallNum++;
    stptr = stFunCall_Fun(t);
    //printf("CALL: callee=%s\n", stptr->name);
    //printf("%d:", depth);
    //indent(n);
    //printf("  args:\n");
    printNode(stFunCall_Args(t), n+4, depth+1);
    break;

  case Assg:
    AssgNum++;
    //printf("ASSG:\n");
    //printf("%d:", depth);
    //indent(n);
    //printf("  Lhs:\n");
    printNode(stAssg_Lhs(t), n+4, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf("  Rhs:\n");
    printNode(stAssg_Rhs(t), n+4, depth+1);
    break;

  case Return:
    ReturnNum++;
    //printf("RETURN:\n");
    printNode(stReturn(t), n+2, depth+1);
    break;

  case For:
    ForNum++;
    //printf("FOR\n");
    //printf("%d:", depth);
    //indent(n);
    //printf("  init:\n");
    printNode(stFor_Init(t), n+4, depth+1);
    // printf("%d:", depth);
    // indent(n);
    // printf("  test:\n");
    printNode(stFor_Test(t), n+4, depth+1);
    // printf("%d:", depth);
    // indent(n);
    // printf("  update:\n");
    printNode(stFor_Update(t), n+4, depth+1);
    // printf("%d:", depth);
    // indent(n);
    // printf("  body:\n");
    printNode(stFor_Body(t), n+4, depth+1);
    // printf("%d:", depth);
    // indent(n);
    //printf("ENDFOR\n");
    break;

  case While:
    WhileNum++;
    //printf("WHILE\n");
    printNode(stWhile_Test(t), n+4, depth+1);
    //printf("%d:", depth);
    //printf("  body:\n ");
    printNode(stWhile_Body(t), n+4, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf("ENDWHILE\n");
    break;

  case If:
    IfNum++;
    //printf("IF\n");
    printNode(stIf_Test(t), n+4, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf("  then:\n");
    printNode(stIf_Then(t), n+4, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf("  else:\n");
    printNode(stIf_Else(t), n+4, depth+1);
    //printf("%d:", depth);
    //indent(n);
    //printf("ENDIF\n");
    break;

  case STnodeList:  /* list of syntax tree nodes */
    STnodeListNum++;
    //printf("{\n");
    /* iterate down the list, printing out each tree in the list in turn */
    for (tntmp0 = t; tntmp0 != NULL; tntmp0 = stList_Rest(tntmp0)) {
      printNode(stList_Head(tntmp0),n+2, depth+1);
    }
    //printf("%d:", depth);
    //indent(n);
    //printf("}\n");
    break;

  //default:
    //fprintf(stderr, "Unknown syntax tree node type %d\n", t->ntype);
  }

  
  
  return;

  // Error,
  // Intcon,
  // Charcon,
  // Stringcon,
  // Var,
  // ArraySubscript,
  // Plus,
  // UnaryMinus,
  // BinaryMinus,
  // Mult,
  // Div,
  // Equals,
  // Neq,
  // Leq,
  // Lt,
  // Geq,
  // Gt,
  // LogicalAnd,
  // LogicalOr,
  // LogicalNot,
  // FunCall,
  // Assg,
  // Return,
  // For,
  // While,
  // If,
  // STnodeList

}
