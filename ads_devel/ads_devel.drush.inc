<?php

/**
 * @file
 * Drush integration of ADS Devel module.
 *
 */

/**
 * Implements hook_drush_COMMAND().
 *
 * Add/edit options to cache-clear command
 */
function ads_devel_drush_cache_clear(&$types) {
  // Resets the cached information about entity types.
  function_exists('entity_info_cache_clear') &&
    $types['entity'] = 'entity_info_cache_clear';

  // Flush all cache from Memcache/Memcached.
  // See: https://www.drupal.org/node/2309657
  module_exists('memcache') &&
    $types['memcache'] = 'memcache_invalidate_cache';

  // Flush all temporary cache from Varnish if used.
  // See: https://www.drupal.org/node/2309663
  module_exists('varnish') &&
    $types['varnish'] = 'varnish_purge_all_pages';

  // Clear PHP OPCache cache if used.
  function_exists('opcache_reset') &&
    $types['opcache'] = 'opcache_reset';

  // Clear PHP XCache cache if used.
  function_exists('xcache_clear_cache') &&
    $types['xcache'] = 'xcache_clear_cache';

  // Clear PHP eAccelerator cache if used.
  function_exists('accelerator_reset') &&
    $types['accelerator'] = 'accelerator_reset';

  // Clear PHP APC cache if used.
  function_exists('apc_clear_cache') &&
    $types['apc'] = 'apc_clear_cache';
}
