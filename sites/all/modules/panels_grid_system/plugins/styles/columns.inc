<?php
/**
 * @file
 * You can configure how many columns the panel region should be.
 * Choose one of available grid systems: 960.gs, Foundation or Bootstrap.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Grid system columns'),
  'description' => t('Span X columns'),
  'render region' => 'panels_grid_system_columns_style_render_region',
  'render pane' => 'panels_grid_system_columns_style_render_pane',
  'settings form' => 'panels_grid_system_columns_settings_form',
  'pane settings form' => 'panels_grid_system_columns_settings_form',
);

/**
 * Render callback for region.
 *
 * @ingroup themeable
 */
function theme_panels_grid_system_columns_style_render_region($vars) {
  $panes = $vars['panes'];
  $settings = $vars['settings'];

  // Rendering region panes.
  $items = array();
  foreach ($panes as $item) {
    $items[] = $item;
  }
  $rendered_items = implode($items);

  $grid_class = panels_grid_system_get_grid_class($settings['grid_system'], $settings);
  $grid_class[] = 'grid-system-row';

  if ($rendered_items) {
    $output = array(
      'items' => $items,
      'rendered_items' => $rendered_items,
      'wrapper_classes' => $grid_class,
      'wrapper_class' => implode(' ', $grid_class),
      'has_row' => $settings['grid_system'] != 'ninesixty',
    );
    return theme('panels_grid_system_region_style', $output);
  }
  else {
    return $rendered_items;
  }
}


/**
 * Render callback for pane.
 */
function theme_panels_grid_system_columns_style_render_pane($vars) {
  $settings = $vars['settings'];
  $grid_classes = panels_grid_system_get_grid_class($settings['grid_system'], $settings);
  $grid_classes[] = 'grid-system-column';
  return '<div' . drupal_attributes(array('class' => $grid_classes)) . '>' . theme('panels_pane', $vars) . '</div>';
}

/**
 * Helper function. Returns settings form for region and pane.
 */
function panels_grid_system_columns_settings_form($style_settings, $display, $pid, $type, $form_state) {
  $grid_system_layouts = array(
    'pgsbootstrap',
    'pgsfoundation',
    'pgsninesixty',
    'pgsrows',
  );
  // Only make the styles available to the relevant layouts.
  if (isset($form_state['display']->layout) && in_array($form_state['display']->layout, $grid_system_layouts)) {
    // Get rid of the 'pgs' prefix and set the layout type on the settings.
    $style_settings['grid_system'] = substr($form_state['display']->layout, 3);
  }

  $form = array();
  // Human readable grid size and offset.
  $columns_array = array('No Columns', '1 Column');
  for ($i = 2; $i <= 12; $i++) {
    $columns_array[$i] = $i . ' Columns';
  }
  $columns_push = array('No Offset', '1 Column');
  for ($i = 2; $i <= 12; $i++) {
    $columns_push[$i] = $i . ' Columns';
  }

  // Available Grid systems.
  $form['grid_system'] = array(
    '#type' => 'hidden',
    '#default_value' => $style_settings['grid_system'],
  );

  // Settings for large screen.
  $form['large_grid'] = array(
    '#type' => 'fieldset',
    '#title' => t('Large Screen'),
    '#attributes' => array('class' => array('grid-region-form')),
  );
  $form['large_grid']['grid_large_qty'] = array(
    '#type' => 'select',
    '#title' => t('Grid Size'),
    '#options' => $columns_array,
    '#default_value' => (isset($style_settings['large_grid']['grid_large_qty'])) ? $style_settings['large_grid']['grid_large_qty'] : '0',
  );
  // The generic row style has no more settings to be added, so return.
  if ($style_settings['grid_system'] == 'rows') {
    return $form;
  }

  $form['large_grid']['grid_large_offset'] = array(
    '#type' => 'select',
    '#title' => t('Grid Offset'),
    '#options' => $columns_push,
    '#default_value' => (isset($style_settings['large_grid']['grid_large_offset'])) ? $style_settings['large_grid']['grid_large_offset'] : '0',
  );

  // The 960 row style has no more settings to be added, so return here.
  if ($style_settings['grid_system'] == 'ninesixty') {
    return $form;
  }

  // Settings for medium screen.
  $form['medium_grid'] = array(
    '#type' => 'fieldset',
    '#title' => t('Medium Screen'),
    '#attributes' => array('class' => array('grid-region-form')),
  );
  $form['medium_grid']['grid_medium_qty'] = array(
    '#type' => 'select',
    '#title' => t('Grid Size'),
    '#options' => $columns_array,
    '#default_value' => (isset($style_settings['medium_grid']['grid_medium_qty'])) ? $style_settings['medium_grid']['grid_medium_qty'] : '0',
  );
  $form['medium_grid']['grid_medium_offset'] = array(
    '#type' => 'select',
    '#title' => t('Grid Offset'),
    '#options' => $columns_push,
    '#default_value' => (isset($style_settings['medium_grid']['grid_medium_offset'])) ? $style_settings['medium_grid']['grid_medium_offset'] : '0',
  );

  // Settings for small screen.
  $form['small_grid'] = array(
    '#type' => 'fieldset',
    '#title' => t('Small Screen'),
    '#attributes' => array('class' => array('grid-region-form')),
  );
  $form['small_grid']['grid_small_qty'] = array(
    '#type' => 'select',
    '#title' => t('Grid Size'),
    '#options' => $columns_array,
    '#default_value' => (isset($style_settings['small_grid']['grid_small_qty'])) ? $style_settings['small_grid']['grid_small_qty'] : '0',
  );
  $form['small_grid']['grid_small_offset'] = array(
    '#type' => 'select',
    '#title' => t('Grid Offset'),
    '#options' => $columns_push,
    '#default_value' => (isset($style_settings['small_grid']['grid_small_offset'])) ? $style_settings['small_grid']['grid_small_offset'] : '0',
  );

  return $form;
}

/**
 * Helper function. Returns grid class.
 */
function panels_grid_system_get_grid_class($grid_system, $settings) {
  $grid_class = array();
  // Default class if the default layout was chosen.
  $gs_classes = array(
    'large' => 'pgs-span-',
  );

  switch ($grid_system) {
    // 960.gs classes.
    case 'ninesixty':
      $gs_classes = array(
        'offset' => 'prefix_',
        'large' => 'grid_',
      );
      break;

    // Bootstrap classes.
    case 'bootstrap':
      $gs_classes = array(
        'offset' => 'offset-',
        'suffix' => '',
        'small' => 'col-xs-',
        'medium' => 'col-sm-',
        'large' => 'col-md-',
      );
      break;

    // Foundation classes.
    case 'foundation':
      $gs_classes = array(
        'offset' => 'offset-',
        'suffix' => 'columns',
        'small' => 'small-',
        'medium' => 'medium-',
        'large' => 'large-',
      );
      break;
  }

  if (!empty($settings['large_grid']['grid_large_qty'])) {
    $grid_class[] = $gs_classes['large'] . $settings['large_grid']['grid_large_qty'];
  }

  // Adding offset classes if needed.
  if (in_array($grid_system, array('bootstrap', 'foundation'))) {
    if (!empty($settings['medium_grid']['grid_medium_qty'])) {
      $grid_class[] = $gs_classes['medium'] . $settings['medium_grid']['grid_medium_qty'];
    }
    if (!empty($settings['small_grid']['grid_small_qty'])) {
      $grid_class[] = $gs_classes['small'] . $settings['small_grid']['grid_small_qty'];
    }
    // Offset for bootstrap and foundation grid systems.
    if (isset($settings['large_grid']['grid_large_offset']) && $settings['large_grid']['grid_large_offset'] != '0') {
      $grid_class[] = $gs_classes['large'] . $gs_classes['offset'] . $settings['large_grid']['grid_large_offset'];
    }
    if (isset($settings['medium_grid']['grid_medium_offset']) && $settings['medium_grid']['grid_medium_offset'] != '0') {
      $grid_class[] = $gs_classes['medium'] . $gs_classes['offset'] . $settings['medium_grid']['grid_medium_offset'];
    }
    if (isset($settings['small_grid']['grid_small_offset']) && $settings['small_grid']['grid_small_offset'] != '0') {
      $grid_class[] = $gs_classes['small'] . $gs_classes['offset'] . $settings['small_grid']['grid_small_offset'];
    }
  }
  elseif ($grid_system == 'ninesixty') {
    // Offset for 960 grid system.
    if (isset($settings['large_grid']['grid_large_offset']) && $settings['large_grid']['grid_large_offset'] != '0') {
      $grid_class[] = $gs_classes['offset'] . $settings['large_grid']['grid_large_offset'];
    }
  }

  if (!empty($grid_class) && !empty($gs_classes['suffix'])) {
    $grid_class[] = $gs_classes['suffix'];
  }

  return $grid_class;
}
