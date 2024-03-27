#include "Calculator.h"

int main()
{
	Calculator c;
	c.SetNotation("(1+2)*((3+4)+5)");
	c.ShowNotation();
	c.Calculate();
}