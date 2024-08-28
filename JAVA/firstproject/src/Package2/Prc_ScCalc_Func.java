package Package2;

interface ScCalculator{
    int fact(int a);
    double square(int a);
    double log(int a);
}

public class Prc_ScCalc_Func implements ScCalculator{

    @Override
    public int fact(int a) {
        int factRes = 1;
        for(int i = 1; i<=a ; i++){
            factRes*=i;
        }
        return factRes;
    }

    @Override
    public double square(int a) {
        return Math.pow(a, 2);
    }

    @Override
    public double log(int a) {
        return Math.log(a);
    }

    public static void main(String[] args) {

    }
}
