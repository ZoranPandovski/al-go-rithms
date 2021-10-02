public class BloomFilter {
  private byte[] set;
  private int keySize, setSize, size;
  private MessageDigest md;

  public BloomFilter(int capacity, int k) {
    setSize = capacity;
    set = new byte[setSize];
    keySize = k;
    size = 0;
    try {
      md = MessageDigest.getInstance("MD5");
    } catch (NoSuchAlgorithmException e) {
      throw new IllegalArgumentException("Error: MD5 Hash not found");
    }
  }

  public boolean insert(Object obj) {
    if(!contains(obj)){
      System.out.println("Inserting " + obj.toString());
      add(obj);
      return true;
    }
    System.out.println("Cannot insert " + obj.toString() + ". Probably already present");
    return false;
  }

  public void makeEmpty() {
    set = new byte[setSize];
    size = 0;
    try {
      md = MessageDigest.getInstance("MD5");
    } catch (NoSuchAlgorithmException e) {
      throw new IllegalArgumentException("Error: MD5 Hash not found");
    }
  }

  public boolean isEmpty() {
    return size == 0;
  }

  public int getSize(){
    return size;
  }

  private int getHash(int i) {
    md.reset();
    byte[] bytes = ByteBuffer.allocate(4).putInt(i).array();
    md.update(bytes, 0, bytes.length);
    return  Math.abs(new BigInteger(1, md.digest()).intValue() % (set.length - 1));
  }

  public void add(Object obj) {
    int[] tmpSet = getSetArray(obj);
    for (int i : tmpSet) set[i] = 1;
    ++size;
  }

  public boolean contains(Object obj) {
    int[] tmpSet = getSetArray(obj);
    for (int i : tmpSet)
      if (set[i] != 1)
        return false;

    return true;
  }

  private int[] getSetArray(Object obj) {
    int[] tmpSet = new int[keySize];
    tmpSet[0] = getHash(obj.hashCode());
    for (int i=1; i< keySize; i++)
      tmpSet[i] = (getHash(tmpSet[i-1]));
    return tmpSet;
  }
}

class BloomFilterTest {
  public void test() {
    String[] valuesToBeInserted = {
        "abound",   "abounds",       "abundance",
        "abundant", "accessable",    "bloom",
        "blossom",  "bolster",       "bonny",
        "bonus",    "bonuses",       "coherent",
        "cohesive", "colorful",      "comely",
        "comfort",  "gems",          "generosity",
        "generous", "generously",    "genial",
        "bluff",    "cheater",       "hate",
        "war",      "humanity",      "racism",
        "hurt",     "nuke",          "gloomy",
        "facebook", "geeksforgeeks", "twitter"
    };
    int valLength = valuesToBeInserted.length;
    int capacity = 10000;
    int k = ((int) Math.floor((double) (capacity / valLength) * Math.log(2)));
    BloomFilter bloomFilter = new BloomFilter(capacity, k);
    for(String s: valuesToBeInserted) {
      bloomFilter.insert(s);
    }
  }
}
