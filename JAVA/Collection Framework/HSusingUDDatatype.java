import java.util.HashSet;
import java.util.Set;

class Student{
    int rollNo;
    String name;
//right click-->Source action -->(Generate Constructor, toString, HashCode and Equals[select rollNo only])
    public Student(int rollNo, String name) {
        this.rollNo = rollNo;
        this.name = name;
    }
    @Override
    public String toString() {
        return "Student [rollNo=" + rollNo + ", name=" + name + "]";
    }
    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + rollNo;
        return result;
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Student other = (Student) obj;
        if (rollNo != other.rollNo)
            return false;
        return true;
    }
}
public class HSusingUDDatatype {
    public static void main(String[] args) {
        Set<Student> set = new HashSet<>();

        Student s1 = new Student(1, "Aman");
        Student s2 = new Student(1, "Piya");

        System.out.println(s1.equals(s2));  //HashCode of s1 and s2 are same. bcoz hashcode are created acc to rollNo

        set.add(new Student(1,"Kashad"));
        set.add(new Student(2,"Shubham"));
        set.add(new Student(1,"Kashad"));

        System.out.println(set);
    }
}
