public class OperationDiv extends Operation{
    @Override
    public double getResult(){
        double result = 0;
        if (getNumberB() == 0){
            throwException();
        }else{
            result = getNumberA() / getNumberB();
        }
        return result;
    }

    public void throwException(){
        try{
            throw new Exception("The div number can not be zero!");
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
