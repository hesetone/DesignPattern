public class MulFactory implements Factory{
    public Operation createOperation(){
        return new OperationMul();
    }
}
