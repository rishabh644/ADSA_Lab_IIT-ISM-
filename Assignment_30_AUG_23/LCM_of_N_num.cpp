#include<iostream>


using namespace std;

int gcd(int a,int b)
{

  if(b>a)
  {
      return gcd(b, a);
  }
  else if(a%b==0)
  {
      return b;
  }
  else
  {
      return gcd(b, a % b);
  }




}



int main()
{

    int n;
    long long int lcm;
    int i;
    cout<<" Enter n n>0 "<<endl;
    cin >> n;
    int arr[n];
    cout << "Enter n number " << endl;
    for (i = 0; i < n;i++)
    {
        cin >> arr[i];
    }
    lcm = arr[0];
    for (i = 1; i < n;i++)
    {
       lcm=(arr[i]*lcm)/gcd(lcm, arr[i]);
    }

    cout << "LCM of given n numbers is " << lcm << endl;

    return 0;
}