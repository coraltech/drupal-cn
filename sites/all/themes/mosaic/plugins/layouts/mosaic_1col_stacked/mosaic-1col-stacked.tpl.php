<div class="layout-1col-stacked layout-wrapper">
  <?php if (!empty($content['top'])): ?>
    <div class="row 1col-top clearfix">
      <div class="limiter">
        <?php print render($content['top']); ?>
      </div>
    </div>
  <?php endif; ?>
  
  <?php if (!empty($content['center'])): ?>
    <div class="row 1col-center clearfix">
      <div class="limiter">
        <?php print render($content['center']); ?>
      </div>
    </div>
  <?php endif; ?>
  
  <?php if (!empty($content['bottom'])): ?>
    <div class="row 1col-bottom">
      <div class="limiter">
        <?php print render($content['bottom']); ?>
      </div>
    </div>
  <?php endif; ?>
</div>
