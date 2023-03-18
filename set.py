class HashSet:
    def __init__(self):
        self.buckets = [[] for _ in range(16)]
        self.size = 0
        
    def __contains__(self, item):
        hash_code = hash(item)
        bucket = self.buckets[hash_code % len(self.buckets)]
        for element in bucket:
            if element == item:
                return True
        return False
        
    def add(self, item):
        if item not in self:
            hash_code = hash(item)
            bucket = self.buckets[hash_code % len(self.buckets)]
            bucket.append(item)
            self.size += 1
            
            if self.size >= len(self.buckets):
                self._resize()
                
    def remove(self, item):
        hash_code = hash(item)
        bucket = self.buckets[hash_code % len(self.buckets)]
        for i, element in enumerate(bucket):
            if element == item:
                bucket.pop(i)
                self.size -= 1
                return True
        return False
    
    def _resize(self):
        new_buckets = [[] for _ in range(len(self.buckets) * 2)]
        for bucket in self.buckets:
            for element in bucket:
                hash_code = hash(element)
                new_bucket = new_buckets[hash_code % len(new_buckets)]
                new_bucket.append(element)
        self.buckets = new_buckets
        
    def __len__(self):
        return self.size
