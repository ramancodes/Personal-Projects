package Package2;

interface Calculator{
    int sum(int ...a);
    int sub(int ...a);
    int mul(int ...a);
    int div(int ...a);
}

public class Prc_Calc_Func implements Calculator{

    @Override
    public int sum(int... a) {
        int sumRes = 0;
        for (int j : a) {
            sumRes += j;
        }
        return sumRes;
    }

    @Override
    public int sub(int... a) {
        int subRes = a[0];
        for(int i = 1; i<a.length; i++){
            subRes-=a[i];
        }
        return subRes;
    }

    @Override
    public int mul(int... a) {
        int mulRes = 1;
        for (int ele : a){
            mulRes*=ele;
        }
        return mulRes;
    }

    @Override
    public int div(int... a) {
        int divRes = a[0];
        try {
            for (int i = 1; i < a.length; i++) {
                divRes /= a[i];
            }
        } catch (Exception e){
//            e.printStackTrace();
            System.out.print("The number cannot be divided by ");
            return 0;
        }
        return divRes;
    }

    public static void main(String[] args) {

    }
}
