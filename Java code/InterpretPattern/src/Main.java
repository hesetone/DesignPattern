import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args){
        Context context = new Context();

        List<AbstractExpression> lst = new ArrayList<AbstractExpression>();
        lst.add(new TerminalExpression());
        lst.add(new NonterminalExpression());
        lst.add(new TerminalExpression());
        lst.add(new TerminalExpression());

        for(AbstractExpression expression : lst){
            expression.interpret(context);
        }
    }
}
