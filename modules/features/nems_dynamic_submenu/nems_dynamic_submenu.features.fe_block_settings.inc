<?php
/**
 * @file
 * nems_dynamic_submenu.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nems_dynamic_submenu_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['tocify-tocify'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'tocify',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'tocify',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ec_resp' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ec_resp',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Page Contents',
    'visibility' => 0,
  );

  return $export;
}
