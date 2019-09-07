#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "conversion.h"

int main(void)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_memmove_invalid_pointers),
    cmocka_unit_test(test_memcpy_invalid_pointers),
    cmocka_unit_test(test_memzero_invalid_pointers),
    cmocka_unit_test(test_reverse_invalid_pointers),
    cmocka_unit_test(test_memmove_no_overlap),
    cmocka_unit_test(test_memmove_src_in_dst),
    cmocka_unit_test(test_memmove_dst_in_src),
    cmocka_unit_test(test_memcpy_check_set),
    cmocka_unit_test(test_memzero_check_set),
     cmocka_unit_test(test_reverse_even_check_set),
     cmocka_unit_test(test_reverse_odd_check_set),
     cmocka_unit_test(test_reverse_character_check_set),
      cmocka_unit_test(test_big_to_little32_invalid_pointers),
    cmocka_unit_test(test_little_to_big32_invalid_pointers),
    cmocka_unit_test(test_big_to_little32_check_set),
    cmocka_unit_test(test_little_to_big32_check_set),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
