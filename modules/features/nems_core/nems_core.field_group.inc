<?php
/**
 * @file
 * nems_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nems_core_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nems_audio_tags|file|audio|form';
  $field_group->group_name = 'group_nems_audio_tags';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'audio';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '5',
    'children' => array(
      0 => 'field_tags',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nems-audio-tags field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nems_audio_tags|file|audio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nems_doc_tags|file|document|form';
  $field_group->group_name = 'group_nems_doc_tags';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '5',
    'children' => array(
      0 => 'field_tags',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nems-doc-tags field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nems_doc_tags|file|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nems_image_tags|file|image|form';
  $field_group->group_name = 'group_nems_image_tags';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '8',
    'children' => array(
      0 => 'field_tags',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nems-image-tags field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nems_image_tags|file|image|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Tags');

  return $field_groups;
}
