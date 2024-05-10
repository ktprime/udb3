#include "../common.c"
#include "khashl.h"

KHASHE_MAP_INIT(KH_LOCAL, intmap_t, intmap, uint32_t, uint32_t, udb_hash_fn, kh_eq_generic)

void test_int(uint32_t N, uint32_t n0, int32_t is_del, uint32_t x0, uint32_t n_cp, udb_checkpoint_t *cp)
{
	uint32_t step = (N - n0) / (n_cp - 1);
	uint32_t i, n, j;
	uint64_t z = 0, x = x0;
	intmap_t *h = intmap_init(6);
	for (j = 0, i = 0, n = n0; j < n_cp; ++j, n += step) {
		for (; i < n; ++i) {
			kh_ensitr_t k;
			int absent;
			uint64_t y = udb_splitmix64(&x);
			k = intmap_put(h, udb_get_key(n, y), &absent);
			if (is_del) {
				if (absent) kh_ens_val(h, k) = i, ++z;
				else intmap_del(h, k);
			} else {
				if (absent) kh_ens_val(h, k) = 0;
				z += ++kh_ens_val(h, k);
			}
		}
		udb_measure(n, kh_ens_size(h), z, &cp[j]);
	}
	intmap_destroy(h);
}
