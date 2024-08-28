package Package2;

class Employee{
    int EmpID;
    String EmpName;
    int EmpSalary;

    public int getEmpID(){
        return EmpID;
    }

    public String getEmpName(){
        return EmpName;
    }

    public int getEmpSalary(){
        return EmpSalary;
    }
}

public class NewClass {
    public static void main(String[] args) {
        Employee Company1 = new Employee();
        Company1.EmpID = 101;
        Company1.EmpName = "John Singh";
        Company1.EmpSalary = 150000;

        System.out.println(Company1.getEmpID());
        System.out.println(Company1.getEmpName());
        System.out.println(Company1.getEmpSalary());
    }
}
