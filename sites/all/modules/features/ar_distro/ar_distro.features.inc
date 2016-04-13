<?php
/**
 * @file
 * ar_distro.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ar_distro_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ar_distro_image_default_styles() {
  $styles = array();

  // Exported image style: gallery_large.
  $styles['gallery_large'] = array(
    'label' => 'Gallery Large (750x350)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 350,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_thumb.
  $styles['gallery_thumb'] = array(
    'label' => 'Gallery Thumb (525x426)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 525,
          'height' => 426,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: imagen_destacada.
  $styles['imagen_destacada'] = array(
    'label' => 'Imagen Destacada (1965x300)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1965,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 1965,
          'height' => 300,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: list.
  $styles['list'] = array(
    'label' => 'List (130x100)',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 130,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: original.
  $styles['original'] = array(
    'label' => 'Original (1920)',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1920,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: wide.
  $styles['wide'] = array(
    'label' => 'Wide (2000x659)',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2000,
          'height' => 659,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ar_distro_node_info() {
  $items = array(
    'noticia' => array(
      'name' => t('Noticia'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Página'),
      'base' => 'node_content',
      'description' => t('Usar <em>páginas</em> para contenido estático'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
