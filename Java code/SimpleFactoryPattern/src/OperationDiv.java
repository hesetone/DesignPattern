
/**
 * Div Operation class
 *
 * @author wsh-nie
 * */

public class OperationDiv extends Operation {
    public double getResult(){
        double result = 0;
        if (getNumberB() == 0){
            throwException();
        }else {
            result = getNumberA() / getNumberB();
        }
        return result;
    }
    private void throwException(){
        try {
            throw new Exception("The div number can't be zero.");
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
