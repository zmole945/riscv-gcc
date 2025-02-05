/* { dg-do compile } */
/* { dg-options "-O2 -fpatchable-function-entry=3,1" } */
/* { dg-final { scan-assembler-times "nop" 2 } } */

extern int a;

/* Respect overriding attributes in the declaration.  */
int f3 (void) __attribute__((patchable_function_entry(2)));

/* F3 should now get 2 NOPs.  */
int
__attribute__((noinline))
f3 (void)
{
  return 5*a;
}
