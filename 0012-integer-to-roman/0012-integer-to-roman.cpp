class Solution {
public:
    string intToRoman(int num) 
    {
        int temp = num;
        int digits = 0;

        while(temp > 0)
        {
            digits++;
            temp = temp/10;
        }    

        string ans;

        if(digits == 1)
        {
            int a = num;
            string part1;
            
            if(a==1)
                part1 = "I";
            else if(a==2)
                part1 = "II";
            else if(a==3)
                part1 = "III";
            else if(a==4)
                part1 = "IV";
            else if(a==5)
                part1 = "V";
            else if(a==6)
                part1 = "VI";
            else if(a==7)
                part1 = "VII";
            else if(a==8)
                part1 = "VIII";
            else if(a==9)
                part1 = "IX";

            ans = part1;
        }
        else if(digits == 2) 
        {
            int a = num%10;
            int b = num - a;

            string part1, part2;

            if(a==1)
                part1 = "I";
            else if(a==2)
                part1 = "II";
            else if(a==3)
                part1 = "III";
            else if(a==4)
                part1 = "IV";
            else if(a==5)
                part1 = "V";
            else if(a==6)
                part1 = "VI";
            else if(a==7)
                part1 = "VII";
            else if(a==8)
                part1 = "VIII";
            else if(a==9)
                part1 = "IX";

            if(b==10)
                part2 = "X";
            else if(b==20)
                part2 = "XX";
            else if(b==30)
                part2 = "XXX";
            else if(b==40)
                part2 = "XL";
            else if(b==50)
                part2 = "L";
            else if(b==60)
                part2 = "LX";
            else if(b==70)
                part2 = "LXX";
            else if(b==80)
                part2 = "LXXX";
            else if(b==90)
                part2 = "XC";

            ans = part2 + part1;
        }
        else if(digits == 3)
        {
            int a = num%10;
            int b = num%100 - a;
            int c = num - a - b;

            string part1, part2, part3;

            if(a==1)
                part1 = "I";
            else if(a==2)
                part1 = "II";
            else if(a==3)
                part1 = "III";
            else if(a==4)
                part1 = "IV";
            else if(a==5)
                part1 = "V";
            else if(a==6)
                part1 = "VI";
            else if(a==7)
                part1 = "VII";
            else if(a==8)
                part1 = "VIII";
            else if(a==9)
                part1 = "IX";

            if(b==10)
                part2 = "X";
            else if(b==20)
                part2 = "XX";
            else if(b==30)
                part2 = "XXX";
            else if(b==40)
                part2 = "XL";
            else if(b==50)
                part2 = "L";
            else if(b==60)
                part2 = "LX";
            else if(b==70)
                part2 = "LXX";
            else if(b==80)
                part2 = "LXXX";
            else if(b==90)
                part2 = "XC";

            if(c==100)
                part3 = "C";
            else if(c==200)
                part3 = "CC";
            else if(c==300)
                part3 = "CCC";
            else if(c==400)
                part3 = "CD";
            else if(c==500)
                part3 = "D";
            else if(c==600)
                part3 = "DC";
            else if(c==700)
                part3 = "DCC";
            else if(c==800)
                part3 = "DCCC";
            else if(c==900)
                part3 = "CM";

            ans = part3 + part2 + part1;
        }
        else{
            int a = num%10;
            int b = num%100 - a;
            int c = num%1000 - a - b;
            int d = num - a - b - c;

            string part1, part2, part3, part4;

            if(a==1)
                part1 = "I";
            else if(a==2)
                part1 = "II";
            else if(a==3)
                part1 = "III";
            else if(a==4)
                part1 = "IV";
            else if(a==5)
                part1 = "V";
            else if(a==6)
                part1 = "VI";
            else if(a==7)
                part1 = "VII";
            else if(a==8)
                part1 = "VIII";
            else if(a==9)
                part1 = "IX";

            if(b==10)
                part2 = "X";
            else if(b==20)
                part2 = "XX";
            else if(b==30)
                part2 = "XXX";
            else if(b==40)
                part2 = "XL";
            else if(b==50)
                part2 = "L";
            else if(b==60)
                part2 = "LX";
            else if(b==70)
                part2 = "LXX";
            else if(b==80)
                part2 = "LXXX";
            else if(b==90)
                part2 = "XC";

            if(c==100)
                part3 = "C";
            else if(c==200)
                part3 = "CC";
            else if(c==300)
                part3 = "CCC";
            else if(c==400)
                part3 = "CD";
            else if(c==500)
                part3 = "D";
            else if(c==600)
                part3 = "DC";
            else if(c==700)
                part3 = "DCC";
            else if(c==800)
                part3 = "DCCC";
            else if(c==900)
                part3 = "CM";

            if(d==1000)
                part4 = "M";
            else if(d==2000)
                part4 = "MM";
            else if(d==3000)
                part4 = "MMM";

            ans = part4 + part3 + part2 + part1;
        }

        return ans;
    }
};