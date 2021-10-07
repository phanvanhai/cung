from invoke import task


@task
def build(ctx):
    print("Building!")
