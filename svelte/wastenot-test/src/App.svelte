<script>
  export let pageTitle;

  let lastInput = Date.now();
  let autoSaveTimer;
  let productQuantity = 1;
  let productName = 'Bacon';
  let autosaveStatusDefault = 'autosaving-alert';
  let autosaveStatus = autosaveStatusDefault;

  let serverStuff = (data) => {

    return new Promise(resolve => {
      console.log({data});
      setTimeout(resolve, 1000);
    });
  }

  async function autoSave(){
    let rightNow = Date.now();
    console.log({rightNow, lastInput});

    let timeSinceLastInput = (rightNow - lastInput);
    let shouldAutoSave = timeSinceLastInput >= 2000;

    if(shouldAutoSave) {
      console.log('Idle, auto-saving')
      let data = {
        product: productName,
        quantity: productQuantity,
      };


      autosaveStatus = `${autosaveStatusDefault} saving`;
      await serverStuff(data).then(()=>{
        console.log('resolved server stuff')
        autosaveStatus = `${autosaveStatusDefault} saved`;
        console.log('foobar');
        setTimeout(() => {
          console.log('foobar settimeout');
          //autosaveStatus = autosaveStatusDefault;
        }, 100);
      });
    }
  }

  const idleHandler = () => {
    console.log('>>>Change')
    lastInput = Date.now();
    clearTimeout(autoSaveTimer);
    autoSaveTimer = setTimeout(autoSave, 2000);
  }

</script>

<main>
  <div class="stylish-form">
    <div class="page-title">
      <h1>{pageTitle}</h1>
    </div>

    <div class="image-container">
      <img class="smooth" src="https://img.estadao.com.br/resources/jpg/2/4/1537398164742.jpg" alt="bacon">
    </div>

    <div class="product-name product-info">
      <h2>Bacon</h2>
      <div>
        Lorem ipsum dolor sit amet, consectetur adipisicing elit. Perspiciatis dolores, neque modi totam nobis unde omnis eum. Vel earum repellendus natus error, soluta quo fuga vitae dolorem pariatur facere voluptas!
      </div>
    </div>

    <div class="input-container product-info">
      <label for="productQuantity">Product Quantity</label>
      <input name="productQuantity"
      value={productQuantity}
      type="number"
      on:change={idleHandler}
      on:keyup={idleHandler}>

      <div id="saved-alert" class="{autosaveStatus}">

        <span class="autosaving-message">Auto-saving...</span>
        <span class="saved-message">Saved! :D</span>
      </div>
    </div>

  </div>
</main>

<style lang="scss">
    main {
    padding: 1em;
    border: 1px solid hotpink;
    margin: 0 auto;
    display: block;
    width: 70%;
  }
  .autosaving-alert{
    font-size: 11px;
    font-style: italic;
    display: inline-block;
    opacity: 0;
    border-radius: 3px;
    padding: 2px 6px;
    color: white;
    .saved-message, .autosaving-message {
      display: none;
    }
    &.saved{
      animation: SavedAnimation 1s ease;
      background: linear-gradient(90deg, #71c356, #4a730c);
      background-size: 400% 400%;
      > .saved-message {
        display: inline-block;
      }
    }
    &.saving{
      animation: SavingAnimation 1s ease infinite;
      background: linear-gradient(90deg, #71c356, #4a730c);
      background-size: 400% 400%;
       > .autosaving-message {
        display: inline-block;
      }
    }
  }

  .stylish-form {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    grid-auto-rows: minmax(100px, auto);
    row-gap: 10px;
    column-gap: 10px;
    > div {
      outline: 1px solid green;
      background: rgba(10,10, 240,.1);
    }
	}
  .page-title{
    text-align: center;
    grid-column: 1 / 4;
    grid-row: 1;
  }
  .image-container{
    grid-column: 1 / 2;
    grid-row: 2 / 5;
    > img {
      position: relative;
      width: 100%;
      height: 100%;
    }
  }
  .product-info{
    padding: 15px;
  }
  .product-name{
    grid-column: 2 / 4;
    grid-row: 2 / 3;
  }
  .input-container{
    grid-column: 2 / 4;
    grid-row: 3 / 5;
  }
	h1 {
		color: #ff3e00;
		text-transform: uppercase;
		font-size: 4em;
		font-weight: 100;
	}

	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}


@keyframes SavingAnimation {
    0%{
      opacity: 0;
      transform: translateX(-40px);
      background-position:0% 50%;
  }
    40%{
      opacity: 1;
      transform: translateX(0px);
      background-position:100% 50%
  }
  80%{
      opacity: 1;
      transform: translateX(0px);
      background-position:100% 50%
  }
    100%{
      opacity: 0;
      ransform: translateX(400px);
      background-position:0% 50%
    }
}

@keyframes SavedAnimation {
    0%{
      opacity: 0;
      transform: translateY(20px);
      background-position:0% 50%;
  }
    40%{
      opacity: 1;
      transform: translateY(0px);
      background-position:100% 50%
  }
  80%{
      opacity: 1;
      transform: translateY(0px);
      background-position:100% 50%
  }
    100%{
      opacity: 0;
      ransform: translateY(400px);
      background-position:0% 50%
    }
}
</style>
