public class AddFactory implements Factory{
    public Operation createOperation(){
        return new OperationAdd();
    }
}
