import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MyHashMapImpl<K, V> implements MyHashMap<K, V>  {
	
	private ArrayList<BucketImpl<K, V>> buckets;

	/**
	 * Build HashMap with nrBuckets buckets 
	 * @param nrBuckets 
	 */
	public MyHashMapImpl(int nrBuckets){
		buckets = new ArrayList<BucketImpl<K,V>>(nrBuckets);
		for(int i = 0; i < nrBuckets; i++)
			buckets.add(new BucketImpl<K,V>());
	}
	/**
	 * translate hashcode
	 */
	private int translate(int hashCode) {
		return Math.abs(hashCode)%buckets.size();
	}
	
	@Override
	public V get(K key) {
		int index = this.translate(key.hashCode());
		for(int i=0;i<buckets.get(index).getEntries().size();i++)
			if(buckets.get(index).getEntries().get(i).getKey().equals(key))return buckets.get(index).getEntries().get(i).getValue();
		return null;
	}

	@Override
	public V put(K key, V value) {
		int index = this.translate(key.hashCode());
		V val = null;
		for(int i = 0; i < buckets.get(index).getEntries().size(); i++)			
			if(buckets.get(index).getEntries().get(i).getKey().equals(key)){
				val = buckets.get(index).getEntries().get(i).getValue();
				buckets.get(index).getEntries().remove(i);
			}
		buckets.get(index).addEntry(key,value);
		return val;
	}

	@Override
	public V remove(K key) {
		int index = this.translate(key.hashCode());
		V val = null;
		for(int i = 0; i < buckets.get(index).getEntries().size(); i++)			
			if(buckets.get(index).getEntries().get(i).getKey().equals(key)){
				val = buckets.get(index).getEntries().get(i).getValue();
				buckets.get(index).getEntries().remove(i);
			}
		return val;
	}

	@Override
	public int size() {
		int s = 0;
		for(Bucket<K,V> b:buckets)
			s += b.getEntries().size();
		return s;
	}

	@Override
	public List<? extends Bucket<K, V>> getBuckets() {
		return this.buckets;
	}
	
	public static class EntryImpl<K, V> implements Entry<K, V>{

		private K key;
		private V value;
		
		public EntryImpl(K key,V value){
			this.key = key;
			this.value = value;
		}
		@Override
		public K getKey() {
			return key;
		}

		@Override
		public V getValue() {
			return value;
		}
		
	}
	
	public static class BucketImpl<K, V> implements Bucket<K, V> {
		
		private List<EntryImpl<K, V>> entries = new LinkedList<EntryImpl<K,V>>();
		
		void addEntry(K key, V value){
			entries.add(new EntryImpl<K,V>(key, value));
		}
		
		@Override
		public List<? extends MyHashMap.Entry<K, V>> getEntries() {
			return entries;
		} 
		
	}

}
