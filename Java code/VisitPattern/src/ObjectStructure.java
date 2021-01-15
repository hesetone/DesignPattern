import java.util.ArrayList;
import java.util.List;

public class ObjectStructure {
    private List<Element> elements = new ArrayList<Element>();

    public void attach(Element e){
        elements.add(e);
    }

    public void detach(Element e){
        elements.remove(e);
    }

    public void accept(Visitor v){
        for(Element e : elements){
            e.accept(v);
        }
    }
}
