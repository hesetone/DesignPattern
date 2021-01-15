public class ConcreteIterator extends Iterator{
    private ConcreteAggregate mAggregate;
    private int mCurrent = 0;

    public ConcreteIterator(ConcreteAggregate aggregate){
        mAggregate = aggregate;
    }

    @Override
    public Object First() {
        return mAggregate.Get(0);
    }

    @Override
    public Object Next() {
        Object obj = null;
        this.mCurrent++;
        if( this.mAggregate.getCount() > this.mCurrent ){
            obj = mAggregate.Get(mCurrent);
        }
        return obj;
    }

    @Override
    public Boolean IsDone() {
        return this.mCurrent >= this.mAggregate.getCount();
    }

    @Override
    public Object currentItem() {
        return this.mAggregate.Get(this.mCurrent);
    }

}
