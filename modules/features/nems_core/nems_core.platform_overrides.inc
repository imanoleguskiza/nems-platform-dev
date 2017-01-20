<?php

/**
 * Implements hook_user_default_permissions_alter().
 */
function nems_core_user_default_permissions_alter(&$permissions) {
  // Permission: 'view own files'.
  if (!empty($permissions['view own files'])) {
    $permissions['view own files']['roles']['webmaster'] = 'webmaster';
  }
}