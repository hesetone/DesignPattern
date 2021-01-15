public class Main {
    public static void main(String[] args){
        ConcreteAggregate concreteAggregate = new ConcreteAggregate();
        for(int i=0; i<26;i++){
            concreteAggregate.Set(i, (char) ('a' + i));
        }

        Iterator iterator = concreteAggregate.createIterator();
        System.out.println(iterator.First().toString());

        while(!iterator.IsDone()){
            System.out.println(iterator.currentItem());
            iterator.Next();
        }
    }
}
