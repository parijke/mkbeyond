<?php
/**
 * @file
 * Layout for panels that will give you between 1 and 12 one-column rows.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Variable number of rows - 960 grid'),
  'category' => t('Grid style'),
  'icon' => 'pgsninesixty.png',
  'theme' => 'panels_grid_system_ninesixty_layout',
  'theme arguments' => array('id', 'content'),
  'settings' => array('num_rows' => NULL),
  'settings form' => 'panels_grid_system_layout_settings_form',
  'regions' => array(
    'r1' => t('Row 1'),
    'r2' => t('Row 2'),
    'r3' => t('Row 3'),
    'r4' => t('Row 4'),
    'r5' => t('Row 5'),
    'r6' => t('Row 6'),
    'r7' => t('Row 7'),
    'r8' => t('Row 8'),
    'r9' => t('Row 9'),
    'r10' => t('Row 10'),
    'r11' => t('Row 11'),
    'r12' => t('Row 12'),
  ),
);
