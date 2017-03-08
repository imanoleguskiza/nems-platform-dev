<?php
/**
 * @file
 * nems_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nems_core_user_default_roles() {
  $roles = array();

  // Exported role: manage blocks.
  $roles['manage blocks'] = (object) array(
    'name' => 'manage blocks',
    'weight' => 9,
  );

  // Exported role: manage files.
  $roles['manage files'] = (object) array(
    'name' => 'manage files',
    'weight' => 8,
  );

  // Exported role: manage main menu.
  $roles['manage main menu'] = (object) array(
    'name' => 'manage main menu',
    'weight' => 10,
  );

  // Exported role: manage users.
  $roles['manage users'] = (object) array(
    'name' => 'manage users',
    'weight' => 6,
  );

  // Exported role: publish content.
  $roles['publish content'] = (object) array(
    'name' => 'publish content',
    'weight' => 7,
  );

  return $roles;
}
