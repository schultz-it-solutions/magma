
/**
 * @file /magma/providers/cryptography/digest.c
 *
 * @brief The message digest context retrieval functions used by the hash and HMAC routines.
 *
 * $Author$
 * $Date$
 * $Revision$
 *
 */

#include "magma.h"

digest_t * digest_name(stringer_t *name) {

	const EVP_MD *result = NULL;
	if (!st_empty(name) && !(result = EVP_get_digestbyname_d(st_char_get(name)))) {
		log_pedantic("The name provided did not match any of the available digest methods. {name = %.*s}", st_length_int(name), st_char_get(name));
	}

	return (digest_t *)result;
}

digest_t * digest_id(int_t id) {

	const EVP_MD *result = NULL;
	if (!(result = EVP_get_digestbyname_d(OBJ_nid2sn_d(id)))) {
		log_pedantic("The id provided did not match any of the available digest methods. {id = %i / name = %s}", id, OBJ_nid2sn_d(id));
	}

	return (digest_t *)result;
}
