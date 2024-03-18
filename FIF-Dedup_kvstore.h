#ifndef KVSTORE_H
#define KVSTORE_H

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/device-mapper.h>
#include <linux/dm-io.h>
#include <linux/dm-kcopyd.h>
#include <linux/list.h>
#include <linux/err.h>
#include <asm/current.h>
#include <linux/string.h>
#include <linux/gfp.h>

#include <linux/scatterlist.h>
#include <asm/page.h>
#include <asm/unaligned.h>
#include <crypto/hash.h>
#include <crypto/md5.h>
#include <crypto/algapi.h>

#include "FIF-Dedup_config.h"

struct kvstore {
	u32 vsize;
	u32 ksize;

	int (*kvs_delete)(struct kvstore *kvs, void *key, int32_t ksize);
	int (*kvs_lookup)(struct kvstore *kvs, void *key, int32_t ksize,
			  void *value, int32_t *vsize);
	int (*kvs_insert)(struct kvstore *kvs, void *key, int32_t ksize,
			  void *value, int32_t vsize);
	int (*kvs_iterate)(struct kvstore *kvs, int (*itr_action)
				(void *key, int32_t ksize, void *value,
				 s32 vsize, void *data), void *data);
};

#endif /* KVSTORE_H */
