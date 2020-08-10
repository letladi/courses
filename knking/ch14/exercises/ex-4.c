/**
 * a) the whole expression is not in parenthesis. Each argument is also not 
 *    in parenthesis in the whole expression
 * b) the whole macro expression must be in parentheses
*/

// what I call an expression is actually called a 'replacement list'

#define AVG(x,y) (((x)+(y))/2)
#define AREA(x,y) ((x)*(y))