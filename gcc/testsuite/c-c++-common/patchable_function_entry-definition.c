/* { dg-do compile } */
/* { dg-options "-O2 -fpatchable-function-entry=3,1" } */
/* { dg-final { scan-assembler-times "nop" 1 } } */

extern int a;

int f3 (void);

/* F3 should now get 1 NOP.  */
int
__attribute__((noinline))
__attribute__((patchable_function_entry(1)))
f3 (void)
{
  return 5*a;
}
