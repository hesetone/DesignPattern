import java.util.ArrayList;
import java.util.List;

public class ConcreteAggregate extends Aggregate{
    private List<Object> mItems = new ArrayList<Object>();

    @Override
    public Iterator createIterator() {
        return new ConcreteIterator(this);
    }

    public Object Get(int index) {
        return this.mItems.get(index);
    }

    public void Set(int index, Object obj){
        this.mItems.add(index,obj);
    }

    public int getCount(){
        return this.mItems.size();
    }
}
