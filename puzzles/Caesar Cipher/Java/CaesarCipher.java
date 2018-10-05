import java.util.*;
import java.lang.Character.*;
class CaesarCipher
{
  public static void main(String[] args)
  {
      Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      String s=sc.next();
      int num=0;
      int k=sc.nextInt()%26;
      char ch[]=new char[n];
      for(int i=0;i<n;i++)
      {
        ch[i]=s.charAt(i);
      }
      for(int i=0;i<n;i++)
      {
        num=0;
        if((int)ch[i]>=65&&(int)ch[i]<=90)
        {
          num=(int)ch[i]+k;
          if(num>90)
          num=(num-90)+64;
          ch[i]=(char)num;
        }
        if((int)ch[i]>=97&&(int)ch[i]<=122)
        {
          num=(int)ch[i]+k;
          if(num>122)
          num=(num-122)+96;
          ch[i]=(char)num;
        }
      }
      for(int i=0;i<n;i++)
      {
        System.out.print(ch[i]);
      }
  }
}
