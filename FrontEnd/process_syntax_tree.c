/*
 * File: process_syntax_tree.c
 * Purpose: Code to traverse the syntax tree of each function and
 *     perform any desired actions.
 */

#include <stdio.h>
#include "syntax-tree.h"

extern void printSyntaxTree(tnode *t, int n, int depth);
extern void printNode(tnode *t, int n, int depth);
int ErrorNum = 0;
int IntconNum = 0;
int CharconNum = 0;
int StringconNum = 0;
int VarNum = 0;
int ArraySubscriptNum = 0;
int PlusNum = 0;
int UnaryMinusNum = 0;
int BinaryMinusNum = 0;
int MultNum = 0;
int DivNum = 0;
int EqualsNum = 0;
int NeqNum = 0;
int LeqNum = 0;
int LtNum = 0;
int GeqNum = 0;
int GtNum = 0;
int LogicalAndNum = 0;
int LogicalOrNum = 0;
int LogicalNotNum = 0;
int FunCallNum = 0;
int AssgNum = 0;
int ReturnNum = 0;
int ForNum = 0;
int WhileNum = 0;
int IfNum = 0;
int STnodeListNum = 0;

/*
 * process_syntax_tree(fn_name, fn_body) -- fn_name is a poiner to
 * the symbol table entry of the function being processed (which can
 * be used, for example, to get the name of the fucntion); fn_body
 * is a pointer to the root of the syntax tree of the function body.
 * This function can be used to carry out tree traversals of the
 * function's syntax tree.
 */
void process_syntax_tree(symtabnode *fn_name, tnode *fn_body)
{
#ifdef DEBUG
  printf("@@FUN: %s\n", fn_name->name);
  printf("@@BODY:\n");
  // printSyntaxTree(fn_body, 4, 0);
  printf("-----\n");

#endif
  // ErrorNum = 0;
  // IntconNum = 0;
  // CharconNum = 0;
  // StringconNum = 0;
  // VarNum = 0;
  // ArraySubscriptNum = 0;
  // PlusNum = 0;
  // UnaryMinusNum = 0;
  // BinaryMinusNum = 0;
  // MultNum = 0;
  // DivNum = 0;
  // EqualsNum = 0;
  // NeqNum = 0;
  // LeqNum = 0;
  // LtNum = 0;
  // GeqNum = 0;
  // GtNum = 0;
  // LogicalAndNum = 0;
  // LogicalOrNum = 0;
  // LogicalNotNum = 0;
  // FunCallNum = 0;
  // AssgNum = 0;
  // ReturnNum = 0;
  // ForNum = 0;
  // WhileNum = 0;
  // IfNum = 0;
  // STnodeListNum = 0;
  printf("@@FUN: %s\n", fn_name->name);
  printNode(fn_body, 4, 0);
  if (ErrorNum != 0)
  {
    printf("Error: %d\n", ErrorNum);
  }
  if (IntconNum != 0)
  {
    printf("Intcon: %d\n", IntconNum);
  }
  if (CharconNum != 0)
  {
    printf("Charcon: %d\n", CharconNum);
  }
  if (StringconNum != 0)
  {
    printf("Stringcon: %d\n", StringconNum);
  }
  if (VarNum != 0)
  {
    printf("Var:%d\n", VarNum);
  }
  if (ArraySubscriptNum != 0)
  {
    printf("ArraySubscript: %d\n", ArraySubscriptNum);
  }
  if (PlusNum != 0)
  {
    printf("Plus: %d\n", PlusNum);
  }
  if (UnaryMinusNum != 0)
  {
    printf("UnaryMinus: %d\n", UnaryMinusNum);
  }
  if (BinaryMinusNum != 0)
  {
    printf("BinaryMinus: %d\n", BinaryMinusNum);
  }
  if (MultNum != 0)
  {
    printf("Mult: %d\n", MultNum);
  }
  if (DivNum != 0)
  {
    printf("Div: %d\n", DivNum);
  }
  if (EqualsNum != 0)
  {
    printf("Equals: %d\n", EqualsNum);
  }
  if (NeqNum != 0)
  {
    printf("Neq: %d\n", NeqNum);
  }
  if (LeqNum != 0)
  {
    printf("Leq: %d\n", LeqNum);
  }
  if (LtNum != 0)
  {
    printf("Lt: %d\n", LtNum);
  }
  if (GeqNum != 0)
  {
    printf("Geq: %d\n", GeqNum);
  }
  if (GtNum != 0)
  {
    printf("Gt: %d\n", GtNum);
  }
  if (LogicalAndNum != 0)
  {
    printf("LogicalAnd: %d\n", LogicalAndNum);
  }
  if (LogicalOrNum != 0)
  {
    printf("LogicalOr: %d\n", LogicalOrNum);
  }
  if (LogicalNotNum != 0)
  {
    printf("LogicalNot: %d\n", LogicalNotNum);
  }
  if (FunCallNum != 0)
  {
    printf("FunCall: %d\n", FunCallNum);
  }
  if (AssgNum != 0)
  {
    printf("Assg: %d\n", AssgNum);
  }
  if (ReturnNum != 0)
  {
    printf("Return: %d\n", ReturnNum);
  }
  if (ForNum != 0)
  {
    printf("For: %d\n", ForNum);
  }
  if (WhileNum != 0)
  {
    printf("While: %d\n", WhileNum);
  }
  if (IfNum != 0)
  {
    printf("If: %d\n", IfNum);
  }
  if (STnodeListNum != 0)
  {
    printf("STnodeList: %d\n", STnodeListNum);
  }
}

// void process_syntax_tree_Node(symtabnode *fn_name, tnode *fn_body) {
// #ifdef DEBUG
//   printf("@@FUN: %s\n", fn_name->name);
//   //printf("@@BODY:\n");
//   printNode(fn_body, 4, 0);
//   printf("-----\n");

// #endif
// }
