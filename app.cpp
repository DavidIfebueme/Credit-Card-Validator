#include <iostream>

using namespace std;

// creating a class of credit card

class credit
{
    public:
        string card_no;
        void type();
        void isValid();
};

// to get the credit card type

void credit:: type()
{
        if((card_no.length()==15) && (card_no[0]=='3') && (card_no[1]=='4'||'7'))
        {
            cout<<"You are trying to validate American Express Card."<<"\n";
        }
        else if((card_no.length()==16) && (card_no[0]=='5') && (card_no[1]=='1'||'2'||'3'||'4'||'5'))
        {
            cout<<"You are trying to validate a Master Card"<<"\n";
        }
        else if((card_no[0]=='4') && (card_no.length()==13||16))
        {
            cout<<"Your are trying to validate a Visa Card"<<"\n";
        }
        else
        {
            cout<<"Card Type is Unknown"<<endl; // @dev changed from "invalid" to "Unknown" because there are other card types aside those given
        }
}

//creating a function that determines if the card number is valid


void credit::isValid()
{
        int len = card_no.length();
            int TotalSum = 0;
            int SumOdd=0;
            int SumEven=0;


            // function that doubles the even placed disgit from the end and sums them. if the resulting double is a two digit number, the addidtion of both difgit is taken in place of the double


            for (int i = len -2; i >= 0; i=i-2) {
                int twice = (((card_no[i])-48)* 2);
                if ( twice > 9) {
                    twice = (twice/10) + (twice % 10);
                }
                SumEven = SumEven + twice;
            }


            // function that doubles the odd placed disgit from the end and sums them. if the resulting double is a two digit number, the addidtion of both digit is taken in place of the double.
            for (int i = len -1; i >=0; i = i-2) {
                SumOdd = SumOdd + (((card_no[i])-48));
            }

            TotalSum = SumEven + SumOdd;



            // to check if the totalsum is  amultiple of 10
            // if yes, then the number is valid, else it is invalid 


            if ( TotalSum % 10 == 0)
            {
                cout<< card_no <<" is valid!!"<<endl;
            }
            else{
                cout<< card_no << " is Invalid!!"<<endl;
            }
}



int main()
{
    credit ob1;
    int i = 0, ans;
    cout<<"________________________________CREDIT CARD VALIDATOR BY GROUP 2________________________________"<<endl;
    cout<<"________________________________USING LUHN'S ALGORITHM________________________________"<<endl;
do{
    cout<<"Enter the Credit card number you want to verify:";
    cin>>ob1.card_no;
    cout<<"\n"<<"Your Credit Card Number is: "<<ob1.card_no <<"\n";
    ob1.type();
    ob1.isValid();
    cout<<"do you want to continue?(1 for yes, 2 for no)"<<endl;
    cin>>ans;
    switch (ans)
    {
    case 1: cout<<endl;
        break;    
    case 2:i ++;
    }
 }while(i==0);
    
    
    return 0;
}

