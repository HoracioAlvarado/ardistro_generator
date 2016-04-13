<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('Página principal'),
  'category' => t('Principal'),
  'icon' => 'principal.png',
  'theme' => 'panels-principal',
  'theme arguments' => array('id', 'content'),
  'css' => 'principal.css',
  'regions' => array(
    'one' => t('Primer bloque'),
    'two' => t('Middle column'),
    'three' => t('Noticias'),
    'four' => t('Center side'),
    'destacado' => t('Bloque destacado'),
    'editorial_one' => t('Editorial main'),
    'editorial_two' => t('Editorial sidebar'),

  ),
);

