public class SubFactory implements Factory{
    public Operation createOperation(){
        return new OperationSub();
    }
}
