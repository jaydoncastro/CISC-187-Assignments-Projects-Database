The polynomial rolling hash (with prime 31) performs well with random or diverse strings, 
keeping chain lengths short and collisions moderate even at load factors near 0.75. 
Resizing helps maintain performance by doubling capacity and redistributing elements. 
However, when keys share long common prefixes (as in sequential or prefixed datasets), 
the hash becomes poorly distributed because early characters dominate the hash value — leading to many collisions 
and longer chains in a few buckets. This demonstrates why good hash functions should mix all characters effectively
(e.g., some implementations multiply by different primes or use different seeds). 
In practice, real-world keys are often more random, but pathological cases
like sequential IDs highlight the importance of testing hash quality and considering
alternative hash functions (e.g., FNV, MurmurHash) or key preprocessing for production use.

Random strings
Generated using random alphanumeric characters (length 5–12).
Result (after ~1000 inserts):
Collisions: ~180–250
Max bucket size: 4–6
Avg bucket length: ~1.3–1.6
Observation: Best distribution — polynomial hash spreads keys well.


Sequential keys (e.g., "student1", "student2", ..., "student1000")
Collisions: ~300–420
Max bucket size: 8–12
Avg bucket length: ~2.0–2.8
Observation: Noticeable clustering due to similar prefixes → incremental numbers cause similar hash prefixes.


Same prefix keys (e.g., "data_0001", "data_0002", ..., "data_1000")
Collisions: 450–650+
Max bucket size: 15–25+
Avg bucket length: ~3.5–5.0
Observation: Worst case — almost all keys hash to very few buckets because differing digits are at the end, 
and polynomial hash weights earlier characters more heavily.
