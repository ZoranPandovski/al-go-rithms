public class Student{
	
	public String name="student";
	public int age=20;
	
	public Student(String name, int age){
		this.name = name;
		this.age = age;
	}
	
	
	@Override
	public boolean equals(Object o){
		if(((Student) o).age != age)
			return false;
		if(!((Student) o).name.equals(name))
			return false;
		return true;
	}
	
	@Override
	public int hashCode(){
		int h = 17;
		h = 37*h + name.hashCode();
		return 37*h + age;
	}
	
	
}
