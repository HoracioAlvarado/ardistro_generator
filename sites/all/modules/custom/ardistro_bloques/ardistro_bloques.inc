<?php

function esNodo(){
  return arg(0) == 'node' && is_numeric(arg(1));
}
function esArea(){
  return (esNodo() && es('area', node_load(arg(1))));
}
function esTramite(){
  return (esNodo() && es('tramite', node_load(arg(1))));
}
function esNoticia(){
  return (esNodo() && es('noticia', node_load(arg(1))));
}
function es($tipo, $nodo){
  return ($nodo->type == $tipo);
}

function obtenerCampo($nodo, $tipo_campo) {
  switch ($tipo_campo) {
    case 'costo':
      $campo = field_get_items('node', $nodo, 'field_tramite_costo', NULL);
      $campo = $campo[0]['safe_value'];
      break;
    case 'requisitos':
      $campo = field_get_items('node', $nodo, 'field_requisitos', NULL);
      $campo = $campo[0]['safe_value'];
      break;
    case 'siglas_area':
      $campo = field_get_items('node', $nodo, 'field_siglas', NULL);
      $campo = $campo[0]['safe_value'];
      break;
    case 'links_relacionados':
      $campo = field_get_items('node', $nodo, 'field_links_relacionados', NULL);
      $campo = obtener($tipo_campo, $campo);
      break;
    case 'paginas_relacionadas':
      $campo = field_get_items('node', $nodo, 'field_paginas_relacionadas', NULL);
      $campo = obtener($tipo_campo, $campo);
      break;
    case 'tipo_tramite':
      $campo = field_get_items('node', $nodo, 'field_tramite_tipo', NULL);
      $campo = isset($campo) ? taxonomy_term_load($campo[0]["target_id"]) : NULL;
      $campo = isset($campo) ? $campo->name : NULL;
      break;
    case 'categoria_noticia':
      $campo = field_get_items('node', $nodo, 'field_categoria', NULL);
      $campo = isset($campo) ? taxonomy_term_load($campo[0]["target_id"]) : NULL;
      $campo = isset($campo) ? $campo->name : NULL;
      break;
    case 'tags':
      $campo = field_get_items('node', $nodo, 'field_tags', NULL);
      $campo = obtener($tipo_campo, $campo);
    default:
      # code...
      break;
  }
  return $campo;
}

function obtener($nombreCampo, $campo){
  $items = array();
  switch ($nombreCampo) {
    case 'tags':
      foreach ($campo as $item) {
        $items[] = $item['taxonomy_term']->name;
      }
      break;
    case 'paginas_relacionadas':
      foreach ($campo as $item) {
        $items[] = $item;
      }
      break;
    case 'links_relacionados':
      foreach ($campo as $item) {
        $items[] = $item;
      }
      break;
    default:
      # code...
      break;
  }
  return $items;
}