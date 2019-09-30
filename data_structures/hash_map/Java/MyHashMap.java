
import java.util.List;

/**
 * Interface for HashMap
 *
 * @param <K> key type
 * @param <V> value type
 */
public interface MyHashMap<K, V> {

    /**
     * Get value for key.
     *
     * @param key
     *
     * @return value or null if key does not exist
     */
    public V get(K key);

    /**
     * Add key-value pair
     *
     * @param key
     * @param value
     * @return previous value or null
     */
    public V put(K key, V value);

    /**
     * Remove key-value pair
     *
     * @param key
     * @return value or null if key does not exist
     */
    public V remove(K key);

    /**
     * HashTable size
     *
     * @return no of keys
     */
    public int size();

    /**
     * Get list of buckets
     *
     * @return a list of Buckets
     */
    public List<? extends Bucket<K, V>> getBuckets();

    /**
     * HashTable Entry
     *
     *
     * @param <K>
     * @param <V>
     */
    public static interface Entry<K, V> {

        /**
         * Intoarce cheia intrarii.
         *
         * @return
         */
        public K getKey();

        public V getValue();
    }

    /**
     * HashTable Bucket
     *
     *
     * @param <K>
     * @param <V>
     */
    public static interface Bucket<K, V> {

        public List<? extends Entry<K, V>> getEntries();
    }
}
