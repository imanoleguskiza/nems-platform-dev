<?php
/**
 * @file
 * nems_press_releases.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nems_press_releases_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nems_press_content|node|press_releases|form';
  $field_group->group_name = 'group_nems_press_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_releases';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_nems_pr_keywords',
      2 => 'field_nems_pr_main_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nems-press-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nems_press_content|node|press_releases|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');

  return $field_groups;
}
