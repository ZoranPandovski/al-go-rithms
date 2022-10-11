public class Complex {
		float real,img;
		Complex(){
			
		}
		Complex(float x,float y){
			real=x;
			img=y;
		}
        Complex add(Complex a) {
			Complex temp=new Complex();
			temp.real=this.real + a.real;
			temp.img=this.img + a.img;
			return temp;
		}
        public static void main(String[]args) {
			Complex c1=new Complex(6.6f,5.8f);
			Complex c2=new Complex(7.4f,8.9f);
			Complex res=c1.add(c2);
            System.out.printf("Addition:%2.2f+%2.2fi",res.real,res.img);
        }
}