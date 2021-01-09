public class DivFactory implements Factory{
    public Operation createOperation(){
        return new OperationDiv();
    }
}
