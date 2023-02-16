/*
 * currency.h
 * -------------------------------------------------------
 * Function prototypes and type definition for safe currency system
 */

struct typedef{
	char* _strBefore;
	char* _strAfter;
} Currency;

Currency* fromString(char* amount);
Currency* fromDouble(double* amount);
Currency* createEmpty();

bool setString(Currency* currency, char* newAmount);
bool setDouble(Currency* currency, double newAmount);
char* getString(Currency* currency);
double getDouble(Currency* currency);

Currency* Add(Currency* a, Currency* b);  
Currency* Sub(Currency* a, Currency* b);
Currency* Mul(Currency* a, Currency* b);
Currency* Div(Currency* a, Currency* b);
Currency* Compare(Currency* a, Currency* b);

Currency* ScalarAdd(Currency* a, double scalar);
Currency* ScalarSub(Currency* a, double scalar);
Currency* ScalarMul(Currency* a, double scalar);
Currency* ScalarDiv(Currency* a, double scalar);
Currency* ScalarCompare(Currency* a, double scalar);

Currency* destroy ();
