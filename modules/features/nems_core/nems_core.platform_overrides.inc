<?php

/**
 * Implements hook_user_default_permissions_alter().
 */
function nems_core_user_default_permissions_alter(&$permissions) {
  // Permission: 'view own files'.
  if (!empty($permissions['view own files'])) {
    $permissions['view own files']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'show format selection for node'.
  if (!empty($permissions['show format selection for node'])) {
    $permissions['show format selection for node']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'show format selection for taxonomy_term'.
  if (!empty($permissions['show format selection for taxonomy_term'])) {
    $permissions['show format selection for taxonomy_term']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'create files'.
  if (!empty($permissions['create files'])) {
    $permissions['create files']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'view files'.
  if (!empty($permissions['view files'])) {
    $permissions['view files']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'edit own image files'.
  if (!empty($permissions['edit own image files'])) {
    $permissions['edit own image files']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'delete own image file'.
  if (!empty($permissions['delete own image file'])) {
    $permissions['delete own image file']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'use text format full_html'.
  if (!empty($permissions['use text format full_html'])) {
    $permissions['use text format full_html']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'use text format filtered_html'.
  if (!empty($permissions['use text format filtered_html'])) {
    $permissions['use text format filtered_html']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'add media from remote sources'.
  if (!empty($permissions['add media from remote sources'])) {
    $permissions['add media from remote sources']['roles']['contributor'] = 'contributor';
    $permissions['add media from remote sources']['roles']['editor'] = 'editor';
    $permissions['add media from remote sources']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'add media from remote sources'.
  if (!empty($permissions['use media wysiwyg'])) {
    $permissions['use media wysiwyg']['roles']['contributor'] = 'contributor';
    $permissions['use media wysiwyg']['roles']['editor'] = 'editor';
    $permissions['use media wysiwyg']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'view own unpublished content'.
  if (!empty($permissions['view own unpublished content'])) {
    $permissions['view own unpublished content']['roles']['contributor'] = 'contributor';
    $permissions['view own unpublished content']['roles']['editor'] = 'editor';
    $permissions['view own unpublished content']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'view own unpublished content'.
  if (!empty($permissions['view revisions'])) {
    $permissions['view revisions']['roles']['contributor'] = 'contributor';
    $permissions['view revisions']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'revert revisions'.
  if (!empty($permissions['revert revisions'])) {
    $permissions['revert revisions']['roles']['contributor'] = 'contributor';
    $permissions['revert revisions']['roles']['editor'] = 'editor';
    $permissions['revert revisions']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'export nodes'.
  if (!empty($permissions['export nodes'])) {
    $permissions['export nodes']['roles']['editor'] = 'editor';
  }
  // Permission: 'create translation jobs'.
  if (!empty($permissions['create translation jobs'])) {
    $permissions['create translation jobs']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'submit translation jobs'.
  if (!empty($permissions['submit translation jobs'])) {
    $permissions['submit translation jobs']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'accept translation jobs'.
  if (!empty($permissions['accept translation jobs'])) {
    $permissions['accept translation jobs']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'translate content'.
  if (!empty($permissions['translate content'])) {
    $permissions['translate content']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'access workbench'.
  if (!empty($permissions['access workbench'])) {
    $permissions['access workbench']['roles']['contributor'] = 'contributor';
  }
  // Permission: 'view all unpublished content'.
  if (!empty($permissions['view all unpublished content'])) {
    $permissions['view all unpublished content']['roles']['contributor'] = 'contributor';
    $permissions['view all unpublished content']['roles']['editor'] = 'editor';
    $permissions['view all unpublished content']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'view moderation history'.
  if (!empty($permissions['view moderation history'])) {
    $permissions['view moderation history']['roles']['contributor'] = 'contributor';
  }
  // Permission: 'view moderation messages'.
  if (!empty($permissions['view moderation messages'])) {
    $permissions['view moderation messages']['roles']['contributor'] = 'contributor';
  }
  // Permission: 'use workbench_moderation my drafts tab'.
  if (!empty($permissions['use workbench_moderation my drafts tab'])) {
    $permissions['use workbench_moderation my drafts tab']['roles']['editor'] = 'editor';
    $permissions['use workbench_moderation my drafts tab']['roles']['contributor'] = 'contributor';
  }
  // Permission: 'use workbench_moderation my drafts tab'.
  if (!empty($permissions['use workbench_moderation my drafts tab'])) {
    $permissions['use workbench_moderation my drafts tab']['roles']['editor'] = 'editor';
    $permissions['use workbench_moderation my drafts tab']['roles']['contributor'] = 'contributor';
  }
  // Permission: 'use workbench_moderation needs review tab'.
  if (!empty($permissions['use workbench_moderation my drafts tab'])) {
    $permissions['use workbench_moderation needs review tab']['roles']['editor'] = 'editor';
    $permissions['use workbench_moderation needs review tab']['roles']['contributor'] = 'contributor';
  }
  // Permission: 'moderate content from draft to needs_review'.
  if (!empty($permissions['moderate content from draft to needs_review'])) {
    $permissions['moderate content from draft to needs_review']['roles']['editor'] = 'editor';
    $permissions['moderate content from draft to needs_review']['roles']['contributor'] = 'contributor';
  }
  // Permission: 'moderate content from needs_review to draft'.
  if (!empty($permissions['moderate content from needs_review to draft'])) {
    $permissions['moderate content from needs_review to draft']['roles']['editor'] = 'editor';
    $permissions['moderate content from needs_review to draft']['roles']['contributor'] = 'contributor';
    $permissions['moderate content from needs_review to draft']['roles']['webmaster'] = 'webmaster';
  }
  // Permission: 'moderate content from needs_review to published'.
  if (!empty($permissions['moderate content from needs_review to published'])) {
    $permissions['moderate content from needs_review to published']['roles']['editor'] = 'editor';
    $permissions['moderate content from needs_review to published']['roles']['webmaster'] = 'webmaster';
  }
}