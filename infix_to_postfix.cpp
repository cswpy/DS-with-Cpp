//============================================================================
// Name         : lab5.cpp
// Author       : Phillip Wang
// Version      : 1.0
// Date Created : 13-03-2019
// Date Modified: 01-03-2020 
// Copyright    : All rights are reserved
// Description  : Convert Infix expression to PostFix and then evaluate it
//============================================================================
#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<ctype.h>

using namespace std;

bool isOperator(char); //Helper method which checks if the input char is an operator
int convertOpToInt (char); //Helper mehtod which converts operators into int so their precdence can be compared
bool isleq(char, char); //Helper method which compare two operators  and return True if first operator has less or equal predence than the right operator
string infix2postfix(string);   //Helper Method which converts an infix notaiton into a postfix notation (lab4)
void displayStack(stack<float> mystack);
float evaluate(string postfix)		//Method which will evaluate a PostfixExpression and return the result
{	
	stack <float> myStack;				//1. Create a stack of type float to store the operands
	for(string::size_type i=0; i<postfix.size(); i++){
        if(isOperator(postfix[i])){
            double res=0;
            double n1 = myStack.top();
            myStack.pop();
            double n2 = myStack.top();
            myStack.pop();
            if(postfix[i]=='+'){
                res = n1+n2;
            }
            else if(postfix[i]=='-'){
                res = n2-n1;
            }
            else if(postfix[i]=='*'){
                res = n2*n1;
            }
            else if(postfix[i=='/']){
                res = n2/n1;
            }
            myStack.push(res);
        }
        else if(isdigit(postfix[i])){
            myStack.push(postfix[i]-'0');
        }
        displayStack(myStack);
        cout<<endl;
    }
    
    
    
    //2.	Scan the POSTFIX expression from left to right for every element
	//	a.	if the element is an operand push it to the stack
	//	b.	if the element is an operator pop 2 elements from the stack, apply the operator on it and push the result back to the stack

	return myStack.top();				//3. return the value from the top of the stack (i.e. the final answer)
}
//=============Main funciton ==============
int main()
{

	while(true)
	{
		string infix;  						//Infix expression
		cout<<"Enter an Infix Expression: ";
		cin>>infix;
	
		if(infix=="exit") 
			break;

		string postfix = infix2postfix(infix);	//Postfix Expression
		float ans=evaluate(postfix);			//evaluate the postfix Expresion
		cout<<"The postfix form is: "<<postfix<<endl;
		cout<<infix<<"="<<ans<<endl;		//print the final answer
	}

	return EXIT_SUCCESS;
}
//=====================================================================
bool isOperator(char ch)
{
	if( ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		return true;
	else
		return false;

}
//Helper mehtod which converts operators into int so their precdence can be compared
int convertOpToInt (char ch)
{
    if (ch=='+' || ch=='-') return 1;
    if (ch=='*' || ch=='/') return 2;
    if (ch=='^') return 3;
    return 0;
}

//Helper method which compare two operators and return True if first operator
//has less or equal predence than the right operator
bool isleq(char opA, char opB)
{
	return (convertOpToInt(opA)<=convertOpToInt(opB));
}

// Helper Method which converts an Infix Notaiton to a Postfix notation
string infix2postfix(string infix)
{
	stack<char> mystack;
    string postfix="";
    mystack.push('(');
    infix+=")";
    for(string::size_type i=0; i<infix.size(); i++){
        if(isOperator(infix[i])){
            while(isleq(infix[i],mystack.top())){
                postfix+=mystack.top();
                mystack.pop();
            }
            mystack.push(infix[i]);
        }
        else if(infix[i]=='('){
            mystack.push('(');
        }
        else if(isdigit(infix[i]) || isalpha(infix[i])){
            postfix+=infix[i];
        }
        else if(infix[i]==')'){
            while(mystack.top()!='('){
                postfix+=mystack.top();
                mystack.pop();
            }
            mystack.pop();
        }
    }
    
    
    // stack <char> mystack;
	// string postfix="";
	// 1.	Push “(“onto Stack, and add “)” to the end of INFIX.
	// 2.	Scan INFIX from left to right and repeat Step 3 to 6 for each element of INFIX until the Stack is empty.
	// 3.	If an operand is encountered, add it to POSTFIX.
	// 4.	If a left parenthesis is encountered, push it onto Stack.
	// 5.	If an operator is encountered, then: 
	// 	a.	Repeatedly pop from Stack and add to POSTFIX each operator (from top of the Stack) which has the same precedence as or higher precedence than operator.
	// 	b.	Add operator to Stack.
	// 	[End of If]
	// 6.	If a ")" is encountered, then: 
	// 	a.	Repeatedly pop from Stack and add to POSTFIX each operator (from top of the Stack) until a left parenthesis is encountered.
	// 	b.	Remove the "(" from stack
	// [End of If]
	// 7.	END.

	return postfix;
}

//Displaying the stack recursively
void displayStack(stack<float> mystack){
    if(mystack.empty())
        return;
    float x = mystack.top();
    mystack.pop();
    displayStack(mystack);
    cout<<x<<" ";
    mystack.push(x);
}