
//Juhwan Lee
//CS-162 Program #1

//This Program computes the running total of all of the purposes
//made as the user shop for items. It gives the user a list of
//possible items to purchase and then the user specifies the price
//and quantity. Then it creates a total amount being spent.

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
  cout.setf(ios::fixed, ios::floatfield); //we want a fixed point presentation
  cout.precision(2); //we want two digits after the decimal point
  cout.setf(ios::showpoint); //if the values are zero, we still want to see them

  int flag = 0;
  int quantity = 0;
  float price = 0.0;
  float runningtotal = 0.0;
  float grandtotal = 0.0;
  char item = '\0';
  char response = '\0';
  char A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z; //declare possible items to purchase
  A = B = C = D = E = F = G = H = I = J = K = L = M = N = O = P = Q = R = S = T = U = V = W = X = Y = Z = '\0';

  while (flag == 0) //big loop (once it gets out of this loop, the program ends)
  {
    cout << "Here are the possible items you can purchase." << endl
    << "A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z" << endl; //give the user a list of possible items to purchase
    cout << "Please select your item." << endl;

    while(flag == 0) //block of code for choosing the item
    {
      response = '\0'; //to refresh the value when the user input for response was not 'Y'
      item = '\0'; //to refresh the value  when the user input for item  was not a single alphabet
      cin >> item;
      cin.ignore(100, '\n');
      item = toupper(item); //lower case to upper case for 'item'
      if ('A' <= item && item <= 'Z') //to check if 'item' is a single alphabet
      {
        cout << "Your item is " << item << ". Is it correct? (Y/N)" << endl;
        while(response != 'Y' && response != 'N')
        {
          cin >> response;
          cin.ignore(100, '\n');
          response = toupper(response); //lower case to upper case for 'response'
          if (response == 'Y')
            flag = 1; //if the user input is 'Y', it moves on to price part
          else if (response == 'N')
            cout << "Please re-select your item." << endl;
          else
            cout << "Please enter Y or N." << endl;
        }
      }
      else
        cout << "The data you provided is not in a correct format. Please choose one item from the given list." << endl;
    }

    flag = 0; //reset the flag for next loop
    cout << "Please type price." << endl;

    while (flag == 0) //block of code for price
    {
      response = '\0'; //to refresh the value when the user input for response was not 'Y'
      price = 0.0; //to refresh the value when the user input for price was wrong
      cin >> price;
      cin.ignore(100, '\n');
      if (price) //to check if the price is number
      {
        cout << "You typed $" << price << ". Is it correct? (Y/N)" << endl;
        while (response != 'Y' && response != 'N')
        {
          cin >> response;
          cin.ignore(100, '\n');
          response = toupper(response);
          if (response == 'Y')
            flag = 1; //if the user input is 'Y', it moves on to quantity part
          else if (response == 'N')
            cout << "Please re-type the price." << endl;
          else
            cout << "Please enter Y or N." << endl;
        }
      }
      else //if the price is not a number
      {
        cout << "The data you provided is not in a correct format. Please type number." << endl;
        cin.clear();
        cin.ignore(100, '\n');
      }
    }

    flag = 0; //reset the flag for next loop
    cout << "Please type quantity." << endl;

    while(flag == 0) //block of code for quantity
    {
      response = '\0'; //to refresh the value when the user input for response was not 'Y'
      quantity = 0; //to refresh the value when the user input for quantity was wrong
      cin >> quantity;
      cin.ignore(100, '\n');
      if (quantity) //to check if the quantity is number
      {
        cout << "You typed " << quantity << ". Is it correct? (Y/N)" << endl;
        while (response != 'Y' && response != 'N')
        {
          cin >> response;
          cin.ignore(100, '\n');
          response = toupper(response);
          if (response == 'Y')
            flag = 1; //if the user input is 'Y', it moves on to next part
          else if (response == 'N')
            cout << "Please re-type the quantity." << endl;
          else
            cout << "Please type Y or N." << endl;
        }
      }
      else //if the quantity is not a number
      {
        cout << "The data you provided is not in a correct format. Please type number." << endl;
        cin.clear();
        cin.ignore(100, '\n');
      }
    }

    runningtotal = runningtotal + (price * quantity); //calculating running total
    response = '\0'; //resetting 'response' for next loop

    cout << "Your running total is : $" << runningtotal << endl;
    cout << "Do you really want to add this to the cart? (Y/N)" << endl;
    while (response != 'Y' && response != 'N')
    {
      cin >> response;
      cin.ignore(100, '\n');
      response = toupper(response);
      if (response == 'Y') //user decides to add it to the cart
      {
        grandtotal = runningtotal; //running total becomes grand total
        response = '\0';
        cout << "Would you like to purchase another item? (Y/N)" << endl;
        while (response != 'Y' && response != 'N')
        {
          cin >> response;
          cin.ignore(100, '\n');
          response = toupper(response);
          if (response == 'Y')
            flag = 0; //it moves back to 'select your item' part
          else if (response == 'N')
            flag = 1; //it makes it to get out of the big loop
          else
            cout << "Please type Y or N." << endl;
        }
      }
      else if (response == 'N') //user decides not to add it to the cart
      {
        runningtotal = runningtotal - (price * quantity); //re-calculating running total
        response = '\0';
        cout << "Would you like to purchase another item? (Y/N)" << endl;
        while (response != 'Y' && response != 'N')
        {
          cin >> response;
          cin.ignore(100, '\n');
          response = toupper(response);
          if (response == 'Y')
            flag = 0; //it moves back to 'select your item' part
          else if (response == 'N')
            flag = 1; //it makes it to get out of the big loop
          else
            cout << "Please type Y or N." << endl;
        }
      }
      else
        cout << "Please type Y or N." << endl;
    }
  }
  cout << "Your grand total is : $" << grandtotal << endl; //it shows the grand total and the program ends
  return 0;
}
