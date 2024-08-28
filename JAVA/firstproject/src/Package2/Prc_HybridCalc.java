package Package2;

public class Prc_HybridCalc {
    public static void main(String[] args) {
        Prc_Calc_Func opCalc = new Prc_Calc_Func();
        Prc_ScCalc_Func opScCalc = new Prc_ScCalc_Func();

        System.out.println(opCalc.sum(2, 4, 5, 6));
        System.out.println(opCalc.sub(2, 4, 5, 6));
        System.out.println(opCalc.mul(2, 4, 5, 6));
        System.out.println(opCalc.div(4, 2, 0));
        System.out.println(opScCalc.square(4));
        System.out.println(opScCalc.log(4));
    }

}
