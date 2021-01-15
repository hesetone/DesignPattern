public class Invoker {
    private Command command;

    public void setCommand(Command command){
        this.command = command;
        System.out.println("获得命令" + command.toString());
    }

    public void executeCommand(){
        command.execute();
    }
}
