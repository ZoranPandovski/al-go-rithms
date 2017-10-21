public class LazyStudent extends Student{
	
	public LazyStudent(String name, int age) {
		super(name, age);
	}

	@Override
	public int hashCode(){
		return 13;
	}
}
